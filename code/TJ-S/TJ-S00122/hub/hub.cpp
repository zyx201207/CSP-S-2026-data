#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e3+5;
struct edge{
	int u,v;
}e[N];
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
    int test_id,T;
    cin>>test_id>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++) cin>>e[i].u>>e[i].v;
        cout<<rand()%(int)(n/2)+1<<endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
