void EscreverPacientesComComorbidade(){

    FILE* funcaoComArquivo;

    char conteudoDoArquivo;
    funcaoComArquivo = fopen("ARQUIVO_COMORBIDADE", "w");

    if (NULL == funcaoComArquivo) {
        printf("NÃO FOI POSSÍVEL ENCONTRAR OS DADOS RELACIONADOS AOS PACIENTES.\n");
    }

    char conteudoLinha[500];
    int i = 0;
    int totalPacientesNaLista = sizeof(dadosPacientes) / sizeof(dadosPacientes[0]);

    for(i=0; i<=totalPacientesNaLista; i++)
    {
        if(strlen(dadosPacientes[i].ComorbidadeDoPaciente) > 0)
        {
            fprintf(funcaoComArquivo, "CODIGO=%s|\n", dadosPacientes[i].Codigo);
            fprintf(funcaoComArquivo, "NOME=%s|\n", dadosPacientes[i].Nome);
            fprintf(funcaoComArquivo, "CPF=%s|\n", dadosPacientes[i].CPF);
            fprintf(funcaoComArquivo, "TELEFONE=%s|\n", dadosPacientes[i].Telefone);
            fprintf(funcaoComArquivo, "ENDERECO=%s|\n", dadosPacientes[i].Endereco);
            fprintf(funcaoComArquivo, "DATANASCIMENTO=%s|\n", dadosPacientes[i].DataNascimento);
            fprintf(funcaoComArquivo, "EMAIL=%s|\n", dadosPacientes[i].Email);
            fprintf(funcaoComArquivo, "DATADODIAGNOSTICO=%s|\n", dadosPacientes[i].DataDoDiagnostico);
            fprintf(funcaoComArquivo, "COMORBIDADEDOPACIENTE=%s|\n\n\n", dadosPacientes[i].ComorbidadeDoPaciente);
        }
    }
    fclose(funcaoComArquivo);
}

void EscreverPacientes(){
    FILE* funcaoComArquivo;
    char conteudoDoArquivo;
    funcaoComArquivo = fopen(ARQUIVO_PACIENTES, "w");

    if (NULL == funcaoComArquivo) {
        printf("NÃO FOI POSSÍVEL ENCONTRAR OS DADOS RELACIONADOS AOS PACIENTES.\n");
    }

    char conteudoLinha[500];
    int i = 0;
    int totalPacientesNaLista = sizeof(dadosPacientes) / sizeof(dadosPacientes[0]);

    for(i=0; i<=totalPacientesNaLista; i++)
    {
        fprintf(funcaoComArquivo, "CODIGO=%s|\n", dadosPacientes[i].Codigo);
        fprintf(funcaoComArquivo, "NOME=%s|\n", dadosPacientes[i].Nome);
        fprintf(funcaoComArquivo, "CPF=%s|\n", dadosPacientes[i].CPF);
        fprintf(funcaoComArquivo, "TELEFONE=%s|\n", dadosPacientes[i].Telefone);
        fprintf(funcaoComArquivo, "ENDERECO=%s|\n", dadosPacientes[i].Endereco);
        fprintf(funcaoComArquivo, "DATANASCIMENTO=%s|\n", dadosPacientes[i].DataNascimento);
        fprintf(funcaoComArquivo, "EMAIL=%s|\n", dadosPacientes[i].Email);
        fprintf(funcaoComArquivo, "DATADODIAGNOSTICO=%s|\n", dadosPacientes[i].DataDoDiagnostico);
        fprintf(funcaoComArquivo, "COMORBIDADEDOPACIENTE=%s|\n", dadosPacientes[i].ComorbidadeDoPaciente);
    }
    fclose(funcaoComArquivo);
}
