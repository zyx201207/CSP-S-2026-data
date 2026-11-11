#include <iostream>
#include <vector>
using namespace std;

int a[500005];
int ans[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

    int n=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> v;
        int cnt[300005]={0};
        for(int x=i;x<=n;x++){
            if(cnt[a[x]]==0){v.push_back(a[x]);cnt[a[x]]++;}
            else{
                while(v.back()!=a[x]){
                    cnt[v.back()]=0;
                    v.pop_back();
                }
            }
        }
        for(int x=1;x<=m;x++){
            ans[x]+=cnt[x];
        }
    }
    for(int x=1;x<=m;x++) cout<<ans[x]<<' ';

	fclose(stdin);
	fclose(stdout);
	return 0;
}
