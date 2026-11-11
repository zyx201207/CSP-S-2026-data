#include<bits/stdc++.h>
using namespace std;
priority_queue <long long,vector<long long>,greater<long long> >q; 
long long n,m,o;
long long b[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		q.push(a);
	}
	for(int i=2;i<=n;i++){
		long long x=q.top();
		q.pop();
		long long y=q.top();
		b[i]=y-x;
//		cout<<b[i]<<" ";
	}
//	cout<<endl;
	long long left=2,right=1,now=0,ans=1,len=1,time=n*10;
	while((time--)&&(right<n)){
		if((b[right+1]*len)<=m){
			m-=(b[right+1]*len);
			now+=b[right+1];
			right++;
			len++;
		}else if(left<=right){
			m+=now;
			now-=b[left];
			left++;
			len--;
		}else{
			left++;
			right++;
		}
//		cout<<m<<" "<<left<<" "<<right<<" "<<now<<" "<<len<<endl;
		ans=max(ans,(2+right-left));
	}
//	cout<<endl;
	cout<<ans;
	return 0;
}
