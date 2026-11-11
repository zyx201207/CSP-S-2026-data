#include<bits/stdc++.h>
using namespace std;
int b[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
	}
	int f1=1,f2=a;
	long long s=0;
	while(f1<f2){
		if(b[f1]>b[f2]){
			if(c[f1]!=c[f2]){
				s+=b[f2];
			}
			b[f1]-=b[f2];
			b[f2]=0;
			f2--;
		}
		else if(b[f1]==b[f2]){
			if(c[f1]!=c[f2]){
				s+=b[f1];
			}
			b[f1]=0;
			b[f2]=0;
			f1++;
			f2--;
		}
		else{
			if(c[f1]!=c[f2]){
				s+=b[f1];
			}
			b[f2]-=b[f1];
			b[f1]=0;
			f1++;
		}
	}
	cout<<s;
}