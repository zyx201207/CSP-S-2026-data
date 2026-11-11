#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
long long a[500005],b[300005],ans[300005],last[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n=read(),m=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(b[a[j]]==0){
				last[a[j]]=j;
				b[a[j]]++;
			}else{
				for(int p=last[a[j]]; p<=j; p++){
					b[a[p]]=0;
				}
				last[a[j]]=j;
				b[a[j]]++;
			}
		}
		for(int j=1; j<=m; j++){
			if(b[j]>0){
				ans[j]+=1;
			}
			b[j]=0;
			last[j]=0;
		}
	}
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
