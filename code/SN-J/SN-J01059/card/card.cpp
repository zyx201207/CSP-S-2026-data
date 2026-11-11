#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
int tong[3010],tong1[3010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}	
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])num++;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=i;
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				tong[a[i]]++;
			}
			if(tong[1]!=0)tong1[1]++;
			if(tong[2]!=0)tong1[2]++;
		}
		cout<<tong1[1]<<" "<<tong1[2]; 
	}else{
		if(num==n-1){
			for(int i=1;i<=n;i++){
				stack<int>st;
				for(int j=1;j<=m;j++){
					tong[j]=0;
				}
				if(a[i]!=a[i+1])st.push(a[i]); 
				for(int j=i+1;j<=n;j++){
					if(a[j]!=a[j-1]){
						st.push(a[j]); 
					}
				}
				while(!st.empty()){
					tong1[st.top()]++;
					st.pop();
				}
			}
			for(int i=1;i<=m;i++){
				cout<<tong1[i]<<" ";
			}
		}else{
			for(int i=1;i<=n;i++){
				stack<int> st;
				for(int j=1;j<=m;j++){
					tong[j]=0;
				}
				for(int j=i;j<=n;j++){
					if(tong[a[j]]==0){
						tong[a[j]]++;
						st.push(a[j]);
					}else{
						while(tong[a[j]]!=0){
							if(st.top()==a[j]){
								tong[a[j]]--;
							}
							st.pop();
						}
						st.push(a[j]);
					}
				}
				while(!st.empty()){
					tong1[st.top()]++;
					st.pop();
				}
			}
			for(int i=1;i<=m;i++){
				cout<<tong1[i]<<" ";
			}
		} 
	}
	return 0;
}
