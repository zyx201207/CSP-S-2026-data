#include <bits/stdc++.h>
using namespace std;
long long l,ans;
string s;
const int N=2e5+5;
struct sth{
	int num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int x;
	char y;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i].c=y;
		a[i].num=x;
	}
	int i=1,j=n;
	while(i<j){
		if(a[i].c!=a[j].c){
			if(a[i].num>=a[j].num){
				ans+=a[j].num;
				a[i].num-=a[j].num;
				a[j].num=0;
				j--;
			}else if(a[i].num<a[j].num){
				ans+=a[i].num;
				a[j].num-=a[i].num;
				a[i].num=0;
				i++;
			}
		}else{
			j--;
		}
	}
	cout<<ans;
	return 0;
}