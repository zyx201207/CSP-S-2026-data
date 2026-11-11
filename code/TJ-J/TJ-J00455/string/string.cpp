#include<bits/stdc++.h>
using namespace std;
struct node{
	int b;
	char c;
}a[200005];
struct Node{
	int b;
	char c;
}d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i].b>>a[i].c;
    for(int i=n,j=1;i>=1&&j<=n;j++,i--){
        d[j].b=a[i].b;
        d[j].c=a[i].c;
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(d[i].c==a[i].c&&d[i].b!=a[i].b)  sum+=abs(d[i].b-a[i].b);
		if(d[i].c!=a[i].c&&d[i].b==a[i].b)  sum+=d[i].b;
		if(d[i].c==a[i].c&&d[i].b==a[i].b){
			continue;
		}
	}
	cout<<sum;
	return 0;
} 
