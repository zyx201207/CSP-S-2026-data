#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[100005],sum,cnt,maxx,minn,w[10005],a[10005][10005],r,x[10005],y[10005],t[10005][10005];
bool qwe=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]!=2){
			qwe=1;
		}
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}

	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		sum=0;
		minn=100000005;
		if(qwe==0){
			for(int z=1;z<=n;z++){
				if(a[z][1]==x[i]&&a[z][2]==y[i]){
					sum=w[a[i][1]]+w[a[i][2]]+t[i][1]+t[i][2];
					minn=min(sum,minn);
				}
			}
		}else{
			break;
		}
		cout<<minn<<endl;
	}
	int chu,muo;
	if(qwe==0) return 0;
	else{
    	for(int i=1;i<=q;i++){
    		for(int j=1;j<=n;j++){
    			muo=0;
    			chu=0;
    			for(int z=1;z<=k[j];z++){
    				if(a[i][z]==x[i]){
						chu++;
					}else if(a[i][z]==y[i]){
						muo++;
					}

				}
				if(muo==1&&chu==1){
					cout<<w[muo]+w[chu]<<endl;
					break;
				}else{
					cout<<w[muo]+w[chu]+t[1][1]<<endl;
					break;
				}

			}
		}
	}

	return 0;
}



