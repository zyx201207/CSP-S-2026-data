//郭昕宇 西安市铁一中学 SN-S00363 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<rand()%10<<"\n";
	}
	return 0;
}
