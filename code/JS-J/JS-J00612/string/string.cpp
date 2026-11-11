#include<bits/stdc++.h>
using namespace std;
struct lo{
	long long m;
	char n;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long b,g=0;
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[i].m>>a[i].n;
		g+=a[i].m;
	}
	string s1="",s2="";
	long long js1=g/2,js2=g/2,js3=1,js4=b;
	while(js1>0){
		for(int i=1;i<=min(js1,a[js3].m);i++){
			s1+=a[js3].n;		
		}
		if(js1>=a[js3].m){
			js1-=a[js3].m;
			js3++;
		}
		else {
			break;
		}
	}
	while(js2>0){
		for(int i=1;i<=min(js2,a[js4].m);i++){
			s2+=a[js4].n;		
		}
		if(js2>=a[js4].m){
			js2-=a[js4].m;
			js4--;
		}
		else {
			break;
		}
	}
	//cout<<s1<<endl<<s2<<endl;
	long long c=0;
	for(int i=0;i<g/2;i++){
		if(s1[i]!=s2[i]) c++;
	}
	cout<<c<<endl;
}
