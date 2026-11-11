#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0);
	string c1,c2,s1,s2;
	int a[2],b[2];
	char ch,ch2;
	cin>>c1>>c2>>s1>>s2;
	int l=c2.size();
	int k=s2.size();
	for(int i=0;i<l;i++){
		if(c2[i]>='0'&&c2[i]<='9'){
			a[i]=c2[i]-'0';
		}
		if(c2[i]>='A'&&c2[i]<='Z'){
			ch=c2[i];
		}
	}
	for(int i=0;i<k;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			b[i]=s2[i]-'0';
		}
		if(s2[i]>='A'&&s2[i]<='Z'){
			ch2=s2[i];
		}
	}
	if(c1==s1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&((ch=='A'&&ch2=='B'||ch=='B'&&ch2=='A')||(ch=='A'&&ch2=='C'||ch=='C'&&ch2=='A')||(ch=='B'&&ch2=='C'||ch=='C'&&ch2=='B')||(ch=='D'&&ch2=='F'||ch=='F'&&ch2=='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a==b&&((ch=='A'&&ch2=='B'||ch=='B'&&ch2=='A')||(ch=='B'&&ch2=='C'||ch=='C'&&ch2=='B')||(ch=='D'&&ch2=='F'||ch=='F'&&ch2=='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
