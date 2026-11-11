#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int z[100010][100010];
int s=INT_MAX;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w;
	vector<vector<int> >a(n);
	vector<vector<int> >t(n);
	for(int i=0;i<m;i++){
		int y;
		cin>>y;
		w.push_back(y);
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++) {
			int ai,ti;
			cin>>ai>>ti;
			a[i].push_back(ai);
			t[i].push_back(ti);
		}
	} 
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=0;
		int r=-1;
		int locx=-1,locy=-1;
		vector<vector<int> > h(n);
		vector<vector<int> > l(n);
		for(int i=0;i<n;i++){
			int locx1=-1;
			int locy1=-1;
			for(int j=0;j<a[i].size();j++){
				if(a[i][j]==x)
					locx1=j;
				if(a[i][j]==y)
					locy1=j;
			}
			if(locx1!=-1&&locy1!=-1){
				if(r==-1){
					locx=locx1;
					locy=locy1;
					r=i;
				}
				else{
					if(a[r][locx]+a[r][locy]>a[i][locx1]+a[i][locy1])
					{
						locx=locx1;
						locy=locy1;
						r=i;
					}
				}
			}else if(locx1!=-1){
				int u=0;
				for(int j=0;j<a[i].size();j++){
					if(a[i][j]!=a[i][locx1])
						h[i].push_back(j);
				}
			
			}else if(locy1!=-1){
				int u=0;
				for(int j=0;j<a[i].size();j++){
					if(a[i][j]!=a[i][locy1])
						l[i].push_back(j);
				}
			
			}	
		}
		if(r!=-1){
			cout<<w[x-1]+w[y-1]+a[r][locx]+a[r][locy]<<'\n';
			continue;
		}else{
			for(int i=0;i<n;i++){
				bool o=0;
				for(int k=0;k<a[i].size();k++)
					if(a[i][k]==x){
						o=1;
						break;
					}
				if(o==0)
					continue;
				for(int j=0;j<m;j++)
				{
					bool b=0;
					for(int k=0;k<a[i].size();k++)
						if(a[i][k]==y){
							b=1;
							break;
						}
					if(b==0)
						continue;
					for(int p=0;p<a[i].size();p++){
						for(int r=0;r<a[j].size();r++){
							if(a[i][p]==a[j][r]){
								int hp=t[i][p]+t[j][r]+t[i][x-1]+t[j][y-1]+w[x-1]+w[y-1];
								s=min(s,hp);
							}
						}
					}
				}
			}
			cout<<s<<'\n';
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
