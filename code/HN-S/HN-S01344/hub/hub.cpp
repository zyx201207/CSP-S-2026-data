#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int s1,s2;
int head,tail;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    cin>>c>>t;
    cin>>n>>m;
    int i,j;
    int mi;
    for(int i=1;i<=n;i++){
    	mi=1;
    	for(int j=1;j<=n;j++){
    		if(!d[j]&&(a[j]==mi||a[j]<m[j])){
    			cin>>a[i][j];
			}
		}
	}
	a[j]=true;
	for(int j=1;j<=n;j++){
		if(!d[j]&&a[i][j]!=0||a[i][j]<d[i][j]){
		}
	}
    q[1][1]=s1;
    q[1][2]=s2;
    f[s1][s2]=true;
    q[1][3]=0;
    while(h<=t){
    	int x,y;
    	if(a[x+fx[i]][y+fy[i]]==false){
    		q[t][1]=x+fx[i];
    		q[t][2]=y+fy[i];
    		q[t][3]=q[h][3]+1;
    		if(f[x+fx[i]][y+fy[i]]==true){
    			break;
			}
		}
		h++;
	}
	cout<<" "<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
