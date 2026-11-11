#include<bits/stdc++.h>
using namespace std;
struct note{
		long long num;
		char a;
}an[200015];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>an[i].num>>an[i].a;
	}
	long long left_=1,right_=n,ans=0;
	while(left_<=right_){
		long long sum=min(an[left_].num,an[right_].num);
		if(an[left_].a!=an[right_].a) ans+=sum;
		if(an[left_].num<an[right_].num){
				an[right_].num-=an[left_].num;
				left_++;
		}
		else{
			an[left_].num-=an[right_].num;
			right_--;
		}
	}
	cout<<ans;
	return 0;
}
