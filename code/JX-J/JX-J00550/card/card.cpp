#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int z[300005];
int ans[300005];
bool vis[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int r=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]])
				while(z[r]!=a[j]&&r>0){
					vis[z[r]]=0;
					r--;
				}
			else r++,z[r]=a[j],vis[a[j]]=1;
		}
		while(r>0){
			vis[z[r]]=0;
			ans[z[r]]++,r--;
		}
	}
	cout<<ans[1];
	for(int i=2;i<=m;i++) cout<<" "<<ans[i];
	cout<<'\n';
    return 0;
}
/*
OS:neng dang mi huo xing wei ma? awa
AWA awa AWA awa QAQ awa AWA awa AWA
//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
//froepen("card.in","r",stdin);
//froepen("card.out","w",stdout);
S na bu liao 1= jiu yao gun hui qu xue whk le QAQ
while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++; while(1) RP++;
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S ge dao jian dan ti+yi dao wo hui de mo ban ti 
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
S bu yao si wei ti,bu yao fu za zuan huan
*/
