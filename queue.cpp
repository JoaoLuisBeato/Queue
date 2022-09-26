#include <iostream>

using namespace std;

class Queue {
public:
	Queue(int size) {
		this->array = new int[size];
		// Seu construtor. Use para iniciar os atributos.
		//cout << "Eu sou um construtor" << endl;
		this->size = size;
		this->frente = 0;
		this->atras = -1;
		this->contador = 0;
	}

	void push(int value) {
		// TODO: Push deve empilhar um valor.
		if(this->atras == this->size-1){
			this->atras = 0;
			this->array[this->atras] = value;
		} else{
			this->array[++this->atras] = value;
		}
		this->contador++;
	}

	void pop() {
		// TODO: Pop deve desempilhar um valor.
		if(this->frente == this->size-1)
			this->frente = 0;
		else
			this->frente++;
		this->contador--;
	}

	int count() {
		// TODO: Deve retornar o total de elementos dentro da pilha.
		return this->contador;
	}

	int front() {
		// TODO: Deve retornar o elemento do topo da pilha
		return this->array[this->frente];
	}

	int back() {
		// Deve retornar o elemento de trás dda fila;
		return this->array[this->atras];
	}

	bool isFull() {
		if(this->contador == this->size-1)
			return true;
		return false;
	}

	bool isEmpty() {
		// TODO
		if(this->contador == 0)
			return true;
		return false;
	}

	void print() {
		// TODO: Esse método deve printar os valores do array!
		int i=this->frente;
		int j=0;
		while(j < contador){
			if(i == this->size)
				i = 0;
			cout << this->array[i] << ", ";
			j++;
			i++;
			//if(i == this->size)
				//i=0;
		}
		cout << endl;
	}

	~Queue() {
		//cout << "Eu sou um destrutor" << endl;
		// Destrutor! Use para desalocar os dados criados com o new
		delete[] array;
	}

private:
	int size; // Atributo privado. Pode ser acessado com this->atributo ou só com atributo]
	int* array;
	int frente;
	int atras;
	int contador;
};

int main() {
	Queue v(5);

	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);
	v.print();

	cout << v.front() << "   " << v.back() << endl;
	return 0;
}
