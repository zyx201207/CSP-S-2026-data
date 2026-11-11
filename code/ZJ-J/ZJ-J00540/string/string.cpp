#include<bits/stdc++.h>//T2->string
using namespace std;
const int N=200010;
struct node {
	long long num;
	char ch;
};
long long n;
node a[N];
long long ret=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i].num>>a[i].ch;
	}/*for(int i=0;i<n;i++){
		cout<<a[i].num<<' '<<a[i].ch<<endl;
	}*/
	long long i=0,j=n-1;
	while(i<j){
		long long mi=min(a[i].num,a[j].num);
		if(a[i].ch!=a[j].ch)ret+=mi;
		a[i].num-=mi;
		a[j].num-=mi;
		if(a[i].num==0)i++;
		if(a[j].num==0)j--;
	}ret+=a[i].num/2;
	cout<<ret;
	return 0;
}
