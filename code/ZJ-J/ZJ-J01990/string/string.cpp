#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char word[200005];
unsigned long long man,answer;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>word[i];
		man+=a[i];
	}
	if(man%2==0){
		long long maxn=man/2;
		unsigned long long k1,k2,k3;
		int flag1=0,flag2=n-1;
		k1=a[flag1],k2=a[flag2];
		while(maxn>=1){
			k3=min(k1,k2);
			if(word[flag1]==word[flag2]){
				k1-=k3,k2-=k3,maxn-=2*k3;
				if(k1==0){
					flag1++;
					k1=a[flag1];
				}if(k2==0){
					flag2--;
					k2=a[flag2--];
				}
			}else{
				k1-=k3,k2-=k3,maxn-=k3;
				if(k1==0){
					flag1++;
					k1=a[flag1];
				}if(k2==0){
					flag2--;
					k2=a[flag2];
				}
				answer+=k3;
			}
		}
	}else if(man%2==1){
		long long maxn=man/2+1;
		unsigned long long k1,k2,k3;
		int flag1=0,flag2=n-1;
		k1=a[flag1],k2=a[flag2];
		while(maxn>1){
			k3=min(k1,k2);
			if(word[flag1]==word[flag2]){
				k1-=k3,k2-=k3,maxn-=2*k3;
				if(k1==0){
					flag1++;
					k1=a[flag1];
				}if(k2==0){
					flag2--;
					k2=a[flag2--];
				}
			}else{
				k1-=k3,k2-=k3,maxn-=k3;
				if(k1==0){
					flag1++;
					k1=a[flag1];
				}if(k2==0){
					flag2--;
					k2=a[flag2];
				}
				answer+=k3;
			}
		}
	}
	cout<<answer;
	return 0;
}