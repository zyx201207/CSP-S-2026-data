//SN-S00490 杨济铭 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int used[505],s[5000][5000];
int c,n,m,d,q;
vector<int> res;
void f(int x,int y,int z){
	for(int p=0;p<m;p++){
		if(p==z&&s[x][p]!=-1){
			y+=s[x][p];
			res.push_back(y);
		}
		if(s[x][p]!=-1&&used[x]==0&&p!=z){
			y+=s[x][p];
			//cout<<p<<" "<<y<<" "<<x<<endl;
			used[p]=1;
			f(p,y,z);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n];
	int a[n][m];
	int t[n][m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			s[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k[i];j++){
			for(int l=j+1;l<k[i];l++){
				s[a[i][j]-1][a[i][l]-1]=t[i][j]+t[i][l];
				s[a[i][l]-1][a[i][j]-1]=t[i][j]+t[i][l];
			}
		}
	}
	/*for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int st[q],ed[q];
	for(int i=0;i<q;i++){
		res.clear();
		cin>>st[i]>>ed[i];
		st[i]-=1;ed[i]-=1;
		f(st[i],0,ed[i]);
		int min=1e9;
		for(int i=0;i<res.size();i++){
			//cout<<res[i]<<" ";
			if(res[i]<min){
				min=res[i];
			}
		}
		cout<<min+w[st[i]]+w[ed[i]]<<endl;
	}
	
	return 0;
}
