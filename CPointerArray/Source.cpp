#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
	Car() {};
	virtual ~Car() {};
	
	void setName( string name) {this->name = name;}
	string getName() {return this->name;}
	void setErrorSize( int eS) {this->errorSize = eS;}
	int getErrorSize() {return this->errorSize;}
	
	void setErrors( int * errors) {
		this->errors = new int[this->errorSize];		//Dynamically create array
		for (int i = 0; i < this->errorSize; i++)
		{
			this->errors[i] = errors[i];
		}
	}
	int * getErrors() {return this->errors;}


private:
	string name;				//Make and model
	int errorSize;
	int * errors;				//Shop errors
};



int main()
{
	int errorList[6];				//Errors to address by pointers
	for (int i = 0; i < 6; i++)
	{
		 errorList[i] = i;			//0,1,2,3,4,5
	}

	Car car1;					//Create car 1
	car1.setName("Ford Mustang");	
	car1.setErrorSize(3);			//Size 3
	int * errCar1 = new int[car1.getErrorSize()];
	errCar1[0] = errorList[3];		//Pointing to the first element pass element 3
	errCar1[1] = errorList[4];
	errCar1[2] = errorList[5];
	car1.setErrors(errCar1);		//Set errors

	Car car2;				//Car 2
	car2.setName("Chevy Impala");
	car2.setErrorSize(1);			//Size 1
	int * errCar2 = new int[car2.getErrorSize()];
	errCar2[0] = errorList[0];
	car2.setErrors(errCar2);//Set errors

	
	cout << "Output cars...." << endl;				//Output
	cout << "Car 1: " << car1.getName() << endl;
	int * carErrors1 = car1.getErrors();
	for (int i = 0; i < car1.getErrorSize(); i++)
	{
		cout << "Car error #" << i << ": " << carErrors1[i] << endl;
	}
	//delete carErrors1;

	cout << "Car 2: " << car2.getName() << endl;
	int * carErrors2 = car2.getErrors();
	for (int i = 0; i < car2.getErrorSize(); i++)
	{
		cout << "Car error #" << i << ": " << carErrors2[i] << endl;
	}
	//delete carErrors2;

	delete errCar1;
	delete errCar2;

	system("pause");
	return 0;
}