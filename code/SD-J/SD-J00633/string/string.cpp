#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int num[N];
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>s[i];
	}
	int sheng=num[n];
	char yu=s[n];
	int cnt=0;
	if(n%2==0){
		for(int i=1,j=n;i<=(n+1)/2,j>(n+1)/2;i++,j--){
			if(yu!=s[i]){
				cnt+=min(sheng,num[i]);
				if(num[i]>sheng){
					sheng=num[i]-sheng;
					yu=s[i];
				}
				if(num[i]<sheng){
					sheng=sheng-num[i];
				}
				if(num[i]==sheng){
					sheng=num[j-1];
					yu=s[j-1];
				}
			}
			if(yu==s[i]){
				if(sheng!=num[i]){
					if(num[i]>sheng){
						sheng=num[i]-sheng;
						yu=s[i];
					}
					if(num[i]<sheng){
						sheng=sheng-num[i];
					}
				}
			}
		}
	}
	else{
		for(int i=1,j=n;i<=(n+1)/2,j>=(n+1)/2;i++,j--){
			if(yu!=s[i]){
				cnt+=min(sheng,num[i]);
				if(num[i]>sheng){
					sheng=num[i]-sheng;
					yu=s[i];
				}
				if(num[i]<sheng){
					sheng=sheng-num[i];
				}
				if(num[i]==sheng){
					sheng=num[j-1];
					yu=s[j-1];
				}
			}
			if(yu==s[i]){
				if(sheng!=num[i]){
					if(num[i]>sheng){
						sheng=num[i]-sheng;
						yu=s[i];
					}
					if(num[i]<sheng){
						sheng=sheng-num[i];
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

