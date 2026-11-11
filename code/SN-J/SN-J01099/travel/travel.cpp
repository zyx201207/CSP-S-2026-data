#include<iostream> 
using namespace std;
int main(){
	freopen("travel.in","r",sudin);
	freopen("travel.out","w",sudout);
	int c1[3],s1[3],c2[3],s2[3];
	for(int i=1;i<=3;i++){
		cin>>c1[i]>>s1[i]>>c2[i]>>s2[i];
		if(c1[i]==c2[i]&&s1[i]==s2[i]){
			cout<<"1";
		}elif(c1[i]==c2[i]&&s1[i+1]==s2[i]){
			cout<<"1";
		}elif(c1[i]==c2[i]&&s1[i-1]==s2[i]{
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
}
