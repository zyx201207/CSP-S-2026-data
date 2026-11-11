#include<bits/stdc++.h>
using namespace std;
long long n,a,shu,b,cnt,aa,shu2;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	cin>>n;
	b=1;
	shu2=1;
	for(int i=1;i<=n;i++){
		cin>>a>>c;	
		if(a>=1e09){
			while(n){
				if(a%10==0){
					if(i==n){
						shu2*=10;
					}
					a/=10;
				}else{
					break;
				}
			}
		}
		for(int j=1;j<=a;j++){
			s[j]=c;
			cnt++;
			if(s[j]==s[j+1]){
				aa=1;
			}
		}
		
	}
	if(aa==1){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=cnt/2;i--){
		if(s[i]!=s[b]){
			s[i]=s[b];
			shu++;
		}
		b++;
	}
	if(shu2>=1e09){
		cout<<shu*shu2*3;	
	}else{
		cout<<shu*shu2;
	}
	return 0;
}