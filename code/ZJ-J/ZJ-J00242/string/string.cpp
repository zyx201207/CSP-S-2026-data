#include<bits/stdc++.h>
using namespace std;
long long n,sum;
struct str{
	long long num;
	char c;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<str>a(n+2);
	for(long long i=0;i<n;i++){
		cin>>a[i].num>>a[i].c;
	}
	long long i=0,j=n-1;
	while(i<=j){
	    if(a[j].c!=a[i].c){
			sum+=min(a[i].num,a[j].num);
		}
		if(a[j].num>a[i].num){
			a[j].num-=a[i].num;
			i++;
		}
		else if(a[j].num<a[i].num){
			a[i].num-=a[j].num;
			j--;
		}
		else{
			i++;
			j--;
		}
    }
	cout<<sum;
	return 0;
}