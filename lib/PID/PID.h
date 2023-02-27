// autor Alison
// email AlisonTristao@hotmail.com

#pragma once // substitui o indef endif
#include <cstdint>
#include <Arduino.h>

class PID{
    public:
        // inicia as constantes apenas rotacionais
        void begin(double kpr, double kir, double kdr, int speed);
        // inicia com constantes tambem translacionais
        void begin(double kpr, double kir, double kdr,
                    double kpt, double kit, double kdt, int speed);
        // atualiza as constantes rotacionais
        void setConst(double kpr, double kir, double kdr);
        // atualiza todas constantes
        void setConst(double kpr, double kir, double kdr,
                    double kpt, double kit, double kdt); 
        // atualiza o valor da velociade
        void setSpeed(int speed);
        void setVerb(bool verb);
        // calcula o PID rotacional - default
        int32_t calcPID(int32_t error);
        // escolhemos qual modo do PID usar 
        int32_t calcPID(int32_t error, uint8_t mode);
        // printa as configurações
        void printConfig();
    private:
        // calculo do PID geral
        int pidEspecif(double kp, double ki, double kd, int32_t error);
        // converte o PID para PWM - ainda precisamos pensar sobre
        int transformForPWM(int PID);
        uint32_t lastTime;
        double kpt, kit, kdt, kpr, kir, kdr;
        int32_t speed, sumError, lastError;
        bool verb;
};

typedef enum {
    ROTACIONAL,
    TRANSLACIONAL
} modos;
