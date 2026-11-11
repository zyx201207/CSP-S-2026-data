#include<bits/stdc++.h>
using namespace std;
string wen;
int jieguo=0;
string b;
int a;
int chang=0;
int duan;
int main(){
	cin>>duan;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=duan;i++){
		cin>>a,b;
		wen=wen+a*b;
		chang=chang+a;
	}
	int pan=chang/2;
	for(int j=1;j<=pan;j++){
		if(!wen[j]==wen[-j]){
			jieguo++;
		}
	}
	cout<<jieguo;
	return 0;
}
