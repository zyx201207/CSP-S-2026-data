//SN-J00778 尚玥轩 西安星光实验学校
#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long b[200000005];
string a2="";
long long n,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>b[i]>>a[i];
		for(long long j=0;j<b[i];j++){
			a2+=a[i];
		}
	}
	long long l=0,r=a2.size()-1;
	while(l<=r){
		if(a2[l]!=a2[r]) cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
