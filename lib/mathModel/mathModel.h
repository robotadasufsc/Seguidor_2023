// autor Alison
// email AlisonTristao@hotmail.com

#pragma once // substitui o indef endif

// use a mesma unidade de medida para todas as informações que infromar
// de preferencia radianos e centimetros (que foi usado nos testes)
class mathModel {
    public:
        /**
         * inicia a biblioteca com os dados do carrinho
        */
        void begin(double carVector[3][2], double wheelsRadius, double actingTime);
        /**
         * define o setPoint de velocidade de cada roda de 
         * acordo com a distancia do sensor em relação
         * a linha
        */
        double* calculateSetPoints(double lineDistance);
        void setVerb(bool verb);
    private:
        /**
         * cordenas X Y
         * carVector[linhas][xy]
         * linha 0 distancia da roda esquerda
         * linha 1 distancia da roda direita
         * linha 2 distancia da linha de sensores
        */
        double carVector[3][2];
        /**
         * setPoint de velocidade de cada roda
         * linha 0 roda esquerda
         * linha 1 roda direita
         * 
         * raio das rodas
        */
        double wheelsSpeed[2], wheelsRadius;
        /** 
         * velocidade angular e velocidade translacional
         * do carrinho
        */
        double omegaCar, translationalSpeed;
        /**
         * tempo definido para que o carrinho alcace a medida calculada
         * (vai resultar a velocidade media translacional)
        */
        double actingTime;
        bool verb;
};