#include <iostream>
#include <typeinfo> //调用typeid()函数用于返回指针或引用所指对象的实际类型
using namespace std;

class Father{
public:
  Father(){ cout <<"obj father is created.\n"; }
	void DoWork(){ DriveACar(); }
	void DoMannulWork(){ RepairTV(); }
  void DriveACar() {  cout <<&typeid(*this).name()[6] <<"is driving a car.\n";  }
protected:
  void RepairTV() {  cout <<&typeid(*this).name()[6] <<"is repairing a TV set.\n";  }
};

class Mother{
public:
  Mother(){ cout <<"obj mother is created.\n"; }
  void SingASong() {  cout <<&typeid(*this).name()[6] <<"is singing a song.\n";  } 
  void DoWork(){ SingASong();  }                                                    //正式工
  void DoMannulWork() { cout <<&typeid(*this).name()[6] <<"is doing mannul work.\n"; }   //小工
};

class Boy : public Father, public Mother{
public:
  Boy(){ cout <<"obj boy is created.\n"; }
  void RepairTV(){ cout <<"boy "; Father::RepairTV(); }
	void SingASong(){ cout <<"boy "; Mother::SingASong(); }
  void PlayPingPong() { cout <<&typeid(*this).name()[6] <<"is playing pingpong.\n";  };
};

void main()
{
   Father father;
   Mother mother;
   Boy boy;

   father.DoWork();
   mother.DoWork();
   mother.DoMannulWork();

   boy.PlayPingPong();
   boy.DriveACar();
   boy.SingASong();

   father.DoMannulWork();
   boy.RepairTV();
}

//修改class Father
//void RepairTV(); 改为public
