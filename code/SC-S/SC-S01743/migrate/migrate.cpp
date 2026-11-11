#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int g,d;
struct Node{
	int mg;
	int num;
};
int bb=-1111111,bb2=-1111111;
Node q={5555555,0};
void dfs(int f,int step){
	if(step>q.mg){
		return;
	}
	if(f==g && bb2!=bb){
		bb2=bb;
		if(step<q.mg){
			q.mg=step;
			q.num=1;
			return;
		}else if(step==q.mg){
			q.num++;
			return;
		}
	}
	for(int i=d;i>=1;i--){
		int ans=1;
		while(1){
			if(arr[f+ans]-arr[f]<i){
				ans++;
			}else if(arr[f+ans]-arr[f]>i){
				break;
			}else if(arr[f+ans]-arr[f]==i){
				ans++;
				break;
			}
		}
		ans--;
		if(ans==0){
			return;
		}
		if(f+ans>g){
			
		}else{
			bb=arr[f];
			dfs(f+ans,step+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,m=0;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>arr[j];
		}
		for(int x=0;x<n-2;x++){
			for(int y=x+2;y<n;y++){
				if(arr[y-1]-arr[y]>d){
					break;
				}
				g=y;
				dfs(x,1);
				if(q.num==2){
					m++;
				}
				q={5555555,0};
				bb=-1111111;
				bb2=-1111111;
			}
		}
		cout<<m<<endl;
		m=0;
		for(int j=0;j<200005;j++){
			arr[j]=0;
		}
		q={5555555,0};
		bb=-1111111;
		bb2=-1111111;
	}
	return 0;
}