#include <bits/stdc++.h>
using namespace std;
long long n,cnt=0,s,b;
struct sb{
	int a;
	char c;
}x[2000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
	}
	s=x[1].a;
	b=x[n].a;
	for(int i=1,j=n;i<=j;i+=0){
		if(x[i].c!=x[j].c){
			cnt+=min(s,b);
		}
		if(s>b){
			j--;
			s-=b;
			b=x[j].a;
		}else if(b>s){
			i++;
			b-=s;
			s=x[i].a;
		}
	}
	cout<<cnt;
	return 0;
}