#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
struct Node{
	int shu;
	string s;
}a[100001];
string qianchuan;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long chang=0;
	string houchuan;
	for(int i=0;i<n;i++){
		cin>>a[i].shu>>a[i].s;
		houchuan=a[i].s;
		for(int j=1;j<=a[i].shu;j++){
			a[i].s+=houchuan;
			qianchuan+=a[i].s;
			chang+=a[i].shu;
		}
	}
	for(long long i=0;i<=ceil(chang/2);i++){
		if(qianchuan[i]!=qianchuan[chang-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
