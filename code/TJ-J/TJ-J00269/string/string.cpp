#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long s;
	char a;
}d[100000000];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>d[i].s>>d[i].a;
	}
	long long cnt=n,i=1,cntt=0;
	while (cnt>i){
		if (d[cnt].a!=d[i].a){
			ans=ans+max(d[i].s,d[cnt].s)-cntt;
		}
		cntt=abs(d[cnt].s-d[i].s);
		cnt--;
		i++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
