#ifndef ARD_MAIN_H
    #define ARD_MAIN_H






    class ard_main 
    {
        public:
            ard_main();


            void receiveData(int byte_count);


            void sendData();


            void setMotors(int p_m1,int p_m2,int p_m3,int p_m4);


            void setSolenoid(bool solState) ;


            bool getStart();


            int getRange(int ID);


            int getPixy(int ID);



            

    };



#endif