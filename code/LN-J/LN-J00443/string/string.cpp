#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
struct stringn{
	int sum;
	char s;
};
int check(string q,string w){
	int end=0,n1=q.size(),j=n1-1;
	for(int i=0;i<n1;i++){
		if(w[i]!=q[j]) end++;
	}
	return end;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,cnt=0;
	cin>>n;
	stringn a[n];
	string x;
	for(int i=0;i<n;i++){
		cin>>a[i].sum>>a[i].s;
		cnt+=a[i].sum;
		int y=0;
		while(y<a[i].sum){
			x+=a[i].s;
			y++;
		}
	}
	bool flag=true;
	bool vis=true;
	int j;
	if(cnt%2==0){
		j=cnt/2;
	}else j=(cnt+1)/2;
	char biaozhun1=x[0],biaozhun2=x[j];
	//cout<<biaozhun1<<biaozhun2;
	for(int i=0;i<j;i++){
		if(x[i]!=biaozhun1){
			flag=false;
			break;
		}
	}
	if(flag){
		for(int i=j;i<n;i++){
			if(x[i]!=biaozhun2){
				flag=false;
				break;
			}
		}
	}
	if(flag){
		cout<<cnt/2;
		return 0;
	}
	string q,w;
	if(cnt%2==0){
		for(int i=0;i<cnt;i++){
			if(i<cnt/2) q+=x[i];
			else w+=x[i];
		}
	}else{
		for(int i=0;i<cnt;i++){
			if(i<(cnt-1)/2) q+=x[i];
			else if(i>=(cnt+1)/2) w+=x[i];
		}
	}
	cout<<min(check(q,w),check(w,q));
	return 0;
}
