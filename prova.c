#include <stdio.h>
#include <stdlib.h>


int pedidosrealizados =0;
int itensvendidos =0;
float faturamentobruto =0;
float descontoconcedido =0;
float faturamentofinal =0;

void menuinicial(){
    printf("\n================================\n");
    printf("CANTINA UCB\n");
    printf("================================\n");
    printf("1-novo pedido\n");
    printf("2-calculadora\n");
    printf("3-simular desconto\n");
    printf("4-relatorio da secao\n");
    printf("0- para sair\n");
    printf("escolha uma opcao: ");
}

void pegar_nome(char nome[30]){
    printf("digite o seu nome: ");
    scanf("%s", nome); 
}


float cardapio(char nome[30]){ 
    int opcao; 
    float valor = 0; 
    int quantidade = 0; 
    float total = 0; 
    float valor_desconto = 0;
    int desconto_aplicado;
    int continuar;
    int id = 0;
    int itens_pedido = 0;
    

    do {
        system("cls"); 
        printf("bem vindo ao cardapio\n"); 
        printf("1-sanduiche R$ 12.00\n"); 
        printf("2-refrigerante R$ 6.00\n"); 
        printf("3-suco R$ 8.00\n"); 
        printf("4-salgado R$ 7.00\n"); 
        printf("5-cafe R$ 4.00\n"); 
        printf("digite a opcao desejada: "); 
        scanf("%d", &opcao); 

        switch (opcao) { 
            case 1: 
                printf("voce escolheu o sanduiche\n"); 
                valor = 12;
                id = 1;
                break; 
            case 2: 
                printf("voce escolheu o refrigerante\n"); 
                valor = 6;
                id = 2;
                break; 
            case 3: 
                printf("voce escolheu o suco\n"); 
                valor = 8;
                id = 3;
                break; 
            case 4: 
                printf("voce escolheu o salgado\n"); 
                valor = 7;
                id = 4;
                break; 
            case 5: 
                printf("voce escolheu o cafe\n"); 
                valor = 4;
                id = 5;
                break; 
            default: 
                printf("opcao invalida\n"); 
                valor = 0;
                break; 
        } 

        if(valor > 0){
            printf("digite a quantidade: "); 
            scanf("%d", &quantidade); 
            while (quantidade <= 0) { 
                printf("digite uma quantidade maior que 0: "); 
                scanf("%d", &quantidade); 
            } 
            total = total + (valor * quantidade);
            itens_pedido = itens_pedido + quantidade;
        }

        system("cls"); 
        printf("o total do pedido ate agora deu :%.2f\n", total); 
        printf("==============================\n"); 
        printf("----------descontos------------\n"); 
        printf("pedidos com total acima de 100 recebem 15 de desconto\n"); 
        printf("pedidos com total acima de 60 recebem 10 de desconto\n"); 
        printf("pedidos com total acima de 30 recebem 5 de desconto\n"); 
        printf("==============================\n"); 

        
        if(total >= 100){ 
            printf("voce recebeu 15 porcento de desconto!\n"); 
            valor_desconto = total * 0.15;
            
            printf("o valor final  e: %.2f\n", total - valor_desconto); 
        }else if(total >= 60 && total < 100){ 
            printf("voce recebeu 10 porcento de desconto\n"); 
            valor_desconto = total * 0.10;
            desconto_aplicado =10;
            printf("o valor final  e: %.2f\n", total - valor_desconto); 
        }else if(total >= 30 && total < 60){ 
            printf("voce recebeu 5 porcento de desconto\n"); 
            valor_desconto = total * 0.05; 
            printf("o valor final  e: %.2f\n", total - valor_desconto); 
        }else{ 
            printf("voce nao recebeu desconto. O valor final e: %.2f\n", total); 
        } 

        printf("Deseja adicionar mais intens (1-sim/0-nao): ");
        scanf("%d", &continuar);
        

    }while(continuar == 1);
    
    pedidosrealizados++;
    itensvendidos = itensvendidos + itens_pedido;
    faturamentobruto = faturamentobruto + total;
    descontoconcedido = descontoconcedido +valor_desconto;
    faturamentofinal = faturamentofinal + (total - valor_desconto);
    
    

    
    total = total - valor_desconto; 
    printf("============================\n");
    printf("      resumo pedido\n");
    printf("============================\n");
    printf("cliente: %s\n", nome);
    printf("itens registrados: %d\n", itens_pedido);
    printf("total bruto: %.2f\n", total);
    printf("desconto: %.2f\n", valor_desconto);
    printf("============================\n");
    printf("pedido registrado com sucesso!\n");
    
    return total;
}

    void menucalculadora(){
        int operador;
        float num1, num2;
        float resultado;
        system("cls");
        printf("=== calculadora ===\n");
        printf("1- somar\n");
        printf("2- subtrair\n");
        printf("3- multiplicar\n");
        printf("4- divisao\n");
        printf("digite a opcao desejada: ");
        scanf("%d", &operador);
        switch(operador){
            case 1:{
                printf("digite o primeiro numero: ");
                scanf("%f", &num1);
                printf("digite o segundo numero: ");
                scanf("%f", &num2);
                resultado = num1 + num2;
                
                printf("o resultado da soma e: %.2f", resultado);
                break;
            }
            case 2:
                printf("digite o primeiro numero: ");
                scanf("%f", &num1);
                printf("digite o segundo numero: ");
                scanf("%f", &num2);
                resultado = num1 - num2;
                
                printf("o resultado da subtracao e: %.2f", resultado);
                break;
            case 3:
                printf("digite o primeiro numero: ");
                scanf("%f", &num1);
                printf("digite o segundo numero: ");
                scanf("%f", &num2);
                resultado = num1 * num2;
                
                printf("o resultado da multiplicacao e: %.2f", resultado);
                break;
            case 4:
                printf("digite o primeiro numero: ");
                scanf("%f", &num1);
                printf("digite o segundo numero: ");
                scanf("%f", &num2);
                while(num2 == 0){
                    printf("nao e possivel divisao por 0\n");
                    printf("digite um numero maior que 0: ");
                    scanf("%f", &num2);
                }
                
                resultado = num1 / num2;
                printf("o resultado da divisao e: %.2f", resultado);
                break;
            default:{
                printf("opcao invalida");
            }
        }
    }
    
    void menudesconto(){
        float total;
        float valor_desconto;
        printf("digite o valor da compra: ");
        scanf("%f", &total);
        if(total >= 100){ 
            printf("faixa encontrada: 15\n"); 
            valor_desconto = total * 0.15;
            printf("o valor do desconto e: %.2f\n", valor_desconto);
            printf("o valor final e: %.2f\n", total - valor_desconto); 
        }else if(total >= 60 && total < 100){ 
            printf("faixa encontrada: 10\n"); 
            valor_desconto = total * 0.10;
            printf("o valor do desconto e: %.2f\n", valor_desconto);
            printf("o valor final e: %.2f\n", total - valor_desconto); 
        }else if(total >= 30 && total < 60){ 
            printf("faixa encontrada: 5\n"); 
            valor_desconto = total * 0.05; 
            printf("o valor do desconto e: %.2f\n", valor_desconto);
            printf("o valor final e: %.2f\n", total - valor_desconto); 
        }else{
            valor_desconto = total;
            printf("o valor do desconto e: %.2f\n", valor_desconto);
            printf("voce nao recebeu desconto. O valor final e: %.2f\n", total); 
        }
        
    }
    
    float menurelario(){
        printf("=========== Relatorio ===========\n");
        printf("pedidos realizados: %d\n", pedidosrealizados);
        printf("itens vendidos: %d\n", itensvendidos);
        printf("faturamento bruto: R$ %.2f\n", faturamentobruto);
        printf("descontos concedidos: R$ %.2f\n", descontoconcedido);
        printf("faturamento final: R$ %.2f\n", faturamentofinal);
        printf("==========================\n");
    }
int main(){
    int opcao;
    char nome[30];
    
    do{
        menuinicial();
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                pegar_nome(nome);
                cardapio(nome);
                break;
            case 2:
                menucalculadora();
                break;
            case 3:
                menudesconto();
                break;
            case 4:
                menurelario();
                break;
            case 0:
                printf("encerrando...\n");
                break;
            default:
                printf("opcao invalida\n");
                break;
        } 
        
    } while(opcao != 0); 

    return 0;
}
