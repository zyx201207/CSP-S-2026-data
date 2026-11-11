#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,num,popnum;
int a[N];
int vis[M];
int cnt[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			num=a[j];
			if(vis[num]!=0){
				while(!st.empty()){
					popnum=st.top();
					st.pop();
					vis[popnum]=0;
					if(popnum==num)break;
				}
			}
			st.push(num);
			vis[num]=1;
		}
		while(!st.empty()){
			popnum=st.top();
			st.pop();
			cnt[popnum]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
