#include<bits/stdc++.h>
using namespace std;
int s[2005];
int er(int a,int c){
	string t,k;
	int b = 0,d = 0,j = 0,v = 1;
	while(a){
		t[b] = a%2+'0';
		a = a/2;
		b++;
	}
	while(c){
		k[d] = c%2+'0';
		c = c/2;
		d++;
	}
	for(int i = 0;i<=max(b,d)-1;i++){
		if(t[i]-'0'==1&&k[i]-'0'==1){
			j+=v;
			v*=2;
		}
		else{
			v*=2;
		}
	}
	return j;
}
int maxx = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>s[i];
	}
	if(m==1){
		for(int i = 1;i<=n;i++){
			if(s[i]>=maxx) maxx = s[i];
		}
	}
	
	if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(er(s[i],s[j])>=maxx) maxx = er(s[i],s[j]);
			}
		}
	}
	cout<<maxx;
	return 0;
}
