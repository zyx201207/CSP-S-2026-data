#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[27]={0};
	int p[200005]={0};
	char e[200005],op;
	scanf("%d",&n);
	long long size=0;
	string t="";
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		scanf("%c",&op);
		scanf("%c",&e[i]);
		a[e[i]-'a'+1]+=p[i];
	}
	for(int i=1;i<=26;i++){
		size+=a[i];
	}
	long long maxn=0;
	for(int i=1;i<=26;i++){
		maxn=(maxn<a[i])?a[i]:maxn;
	}
	if(size%2){
		if(maxn>size/2+1){
			cout<<size-maxn;
			return 0;
		}
	}
	else{
		if(maxn>=size/2){
			cout<<size-maxn;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t+=e[i];
		}
	}
	long long k=0;
	for(int i=1;i<size/2+1;i++){
		if(t[i]!=t[size-i+1]){
			t[size-i+1]=t[i];
			k++;
		}
	}
	cout<<k;
	return 0;
}
