#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
struct tt{
	long long x;
	char aa;
}a[N];
long long n,len,tmp,ans;
void xzk(){
	/*
	aaaacc|ccbbaa
	     ^ ^
	*/
	long long cnt=0,L=1,R=n,SY=a[n].x;
	while(L<=n){
		tmp=cnt+a[L].x;
		if(tmp<=len/2){
			long long MB=a[L].x;
			char LDQ=a[L].aa;
			while(R>=1&&MB){
				char RDQ=a[R].aa;
				if(SY<=MB){
					MB-=SY;
					if(LDQ!=RDQ){
						ans+=SY; 
					}
					R--;
					SY=a[R].x;
				} 
				else{
					SY-=MB;
					if(LDQ!=RDQ){
						ans+=MB;
					}
					MB=0;
				}
			}
			cnt+=a[L].x;
			L++;
		}
		else{
			break;
		}
	}
	if(L<R){
		char LDQ=a[L].aa;
		char RDQ=a[R].aa;
		if(LDQ!=RDQ){
			ans+=SY;
		}
	}
	cout<<ans;
}
void yal(){
	/*
	aaaacc|c|ccbbaa
	       ^
	*/
	long long cnt=0,L=1,R=n,SY=a[n].x;
	while(L<=n){
		tmp=cnt+a[L].x;
		if(tmp<=len/2){
			long long MB=a[L].x;
			char LDQ=a[L].aa;
			while(R>=1&&MB){
				char RDQ=a[R].aa;
				if(SY<=MB){
					MB-=SY;
					if(LDQ!=RDQ){
						ans+=SY; 
					}
					R--;
					SY=a[R].x;
				} 
				else{
					SY-=MB;
					if(LDQ!=RDQ){
						ans+=MB;
					}
					MB=0;
				}
			}
			cnt+=a[L].x;
			L++;
		}
		else{
			break;
		}
	}
	if(L<R){
		char LDQ=a[L].aa;
		char RDQ=a[R].aa;
		if(LDQ!=RDQ){
			ans+=SY;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].aa;
		len+=a[i].x;
	}
	if(len%2==0){
		xzk();
	}
	else{
		yal();
	}
	return 0;
}
