#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5*5+200;
int n,m,A,B;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	/*ios::sync_with_stdio(false);
	cin.tie(nullptr);*/
	//cout<<(int)sqrt(5);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i==1||i==2) continue;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			B=1;
			//cout<<"B";
		}
	}
	A=a[2]-a[1];
	if(B==0){
			int res=0;
			for(int i=1;i<n;i++){
				if(i%2==1) res+=A;
				m-=res;
				if(m<0){
					cout<<i;
					return 0;
				}
			}
			cout<<n-1;
			return 0;
	} 
	if(n<=5000){
		priority_queue<int>q;
		int cnt=0,maxx=0,mm=m;
		for(int i=1;i<=n;i++){
			cnt=0,mm=m; 
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				int x=abs(a[i]-a[j]);
				q.push(x);
				mm-=x;
				cnt++;
				//cout<<mm<<endl;
				if(mm<0){
					mm+=q.top();
					q.pop();
					//cout<<mm<<endl;
					cnt--;
					//cout<<7878<<" "; 
					//cout<<cnt<<" ";
					if(mm<0){
						//cout<<j<<endl;
						break;
					}
				}
				//cout<<cnt<<" ";
			}
			maxx=max(maxx,cnt);
			//break;
		}
		cout<<maxx+1;
		return 0;
	}int k=1,j=n;
	for(;k<=j-2;){
		int x=abs(a[k]-a[k+1]);
		int y=abs(a[j]-a[j-1]);
		if(x<y) j--;
		else if(x>y) k++;
		else j--,k++;
	}
	int i=k;
	priority_queue<int>q;
	int cnt=0,maxx=0,mm=m; 
	for(int j=1;j<=n;j++){
		if(j==i) continue;
		int x=abs(a[i]-a[j]);
				q.push(x);
				mm-=x;
				cnt++;
				//cout<<mm<<endl;
				if(mm<0){
					mm+=q.top();
					q.pop();
					//cout<<mm<<endl;
					cnt--;
					//cout<<7878<<" "; 
					//cout<<cnt<<" ";
					if(mm<0){
						//cout<<j<<endl;
						break;
					}
				}
				//cout<<cnt<<" ";
	}
	maxx=max(maxx,cnt);
	i=j;
	priority_queue<int>p;
	cnt=0,mm=m;
	for(int j=1;j<=n;j++){
		if(j==i) continue;
		int x=abs(a[i]-a[j]);
				p.push(x);
				mm-=x;
				cnt++;
				//cout<<mm<<endl;
				if(mm<0){
					mm+=p.top();
					p.pop();
					//cout<<mm<<endl;
					cnt--;
					//cout<<7878<<" "; 
					//cout<<cnt<<" ";
					if(mm<0){
						//cout<<j<<endl;
						break;
					}
				}
				//cout<<cnt<<" ";
	}
	maxx=max(maxx,cnt);
	cout<<maxx+1;
	return 0;
}//5 8 -3 -1 2 2 7

