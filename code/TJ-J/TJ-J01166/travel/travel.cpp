#include<cstdio>
#include<iostream>
#include<string>
std::string trainR,seatR,trainX,seatX;
bool ans1=false,ans2=false,ans3=false,ans4=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::cin>>trainR>>seatR>>trainX>>seatX;
	if(trainR==trainX){
		ans1=true;
		if(seatR[0]==seatX[0]&&seatR[1]==seatX[1]){
			ans2=true;
			if(seatR[2]>='A'&&seatR[2]<='C'&&seatX[2]>='A'&&seatX[2]<='C'){
				ans3=ans4=true;
				if(seatR[2]=='A'&&seatX[2]=='C') ans4=false;
				if(seatR[2]=='C'&&seatX[2]=='A') ans4=false;
			}if(seatR[2]>='D'&&seatR[2]<='F'&&seatX[2]>='D'&&seatX[2]<='F') ans3=ans4=true;
		}
	}std::printf("%d%d%d%d\n",ans1,ans2,ans3,ans4);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
