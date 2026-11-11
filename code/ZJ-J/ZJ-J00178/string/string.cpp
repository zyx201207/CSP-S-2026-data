#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
struct node{
	long long num;
	char ch;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].num>>a[i].ch;
	}
	int x=1,y=n;
	while(x<y){
		if(a[x].ch!=a[y].ch){
			sum+=min(a[x].num,a[y].num);
		}
		int xx=min(a[x].num,a[y].num);
		a[x].num-=xx;
		a[y].num-=xx;
		if(a[x].num==0)x++;
		if(a[y].num==0)y--;
	}
	cout<<sum<<endl;
	return 0;
}

