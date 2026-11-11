#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
long long cnt,sum;
int n,a[maxn],tmp_a;
char c[maxn],tmp_c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d %c",&a[i],&c[i]),sum+=a[i];
	int i=1,j=n;
	while(i<j){
		tmp_a=min(a[i],a[j]);
		if(c[i]!=c[j])cnt+=tmp_a;
		a[i]-=tmp_a,a[j]-=tmp_a;
		if(!a[i])i++;
		if(!a[j])j--;
	}
	cout<<cnt;
	return 0;
}