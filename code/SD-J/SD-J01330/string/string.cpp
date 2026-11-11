#include<bits/stdc++.h>
using namespace std;
long long l,cnt,n;
struct nono{
	long long a;
	char x;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].x;
		l+=s[i].a;;
	}
	long long j=n,q;
	l=l/2+1;
	for(int i=1;i<=n;i++){
		if(s[i].a>=l){
			q=i;
			break;	
		}else{
			l-=s[i].a;
		}
	}
	for(int i=1;i<=q;i++){
		int m=s[i].a;
		while(m){
			if(s[j].x==s[i].x){
				if(s[j].a>m){
					s[j].a-=m;
					m=0;
				}else{
					m-=s[j].a;
					s[j].a=0;
					j--;
				}	
			}else{
				if(s[j].a>m){
					s[j].a-=m;
					cnt+=m;
					m=0; 
				}else{
					m-=s[j].a;
					cnt+=s[j].a;
					s[j].a=0;
					j--;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
