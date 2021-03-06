/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Validação de uma rede neural                                              *
 * --------------------------------------------------------------------------*/



#include "defs.hh"


using std::ifstream;

float bin_to_float(float * v){
    int max = 0;
    for(int i = 1; i < SIZE_OUT; i++)
        if(v[i] > v[max])
            max = i;
    return float(max);
}

float validacao(struct fann * rede) {
    float entradas[64], saida_real[10];
    int linhas, n_entradas, n_saidas;
    ifstream arq("input/validacao/validacao.convertida.tes");
    arq >> linhas >> n_entradas >> n_saidas;
    
    int erros = 0;

    for(int k = 0; k < linhas; k++){
        for(int i = 0; i < n_entradas; i++)
            arq >> entradas[i];
        for(int i = 0; i < n_saidas; i++)
            arq >> saida_real[i];

        float * saidas = fann_run(rede, entradas);              //calcula as saídas da rede para validação
        float s_rede = bin_to_float(saidas), s_real = bin_to_float(saida_real);
        
        if(s_rede != s_real)
            erros++;
      
    }
    return float(erros)/linhas;
}
