#include<bits/stdc++.h>
using namespace std;
#define int unsigned
map<int,int>mp;
int n,m;
vector<int>x;
void solve(vector<int> a,int rol){
    vector<int>desk;
    int end=0;
    for(int i=rol;i<=n;i++){
	int now=a[i];
	bool remove=false;
	for(int k=0;k<end;k++){
	    if(now==desk[k]){
		swap(desk[k],now);
		remove=true;
		end=k+1;
		break;
	    }
 	}		
	if(not remove){
		desk.push_back(-1);
		swap(desk[end],now);
		end++;
	}
    }
    
    for(int i=0;i<end;i++)
	mp[desk[i]]++;
}
signed main(){
   
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    x.push_back(-1);
    cin>>n>>m;
    for(int i=0;i<n;i++){
	int a;
	cin>>a;
	x.push_back(a);
	mp[a]=0;
    }
    for(int i=1;i<=n;i++)
	    solve(x,i);
    for(int i=1;i<=m;i++)
	cout<<mp[i]<<' ';
    return 0;
}
// What can I say!F**K NV!!!!!!
// Maybe only one bugs that i didnt found!!!!!!But no time!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH!
// SUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUX!
// WHERE ARE THE EGGS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// emm..
// They seems no need...
