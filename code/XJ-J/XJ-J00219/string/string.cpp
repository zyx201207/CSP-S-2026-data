#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
string s;
int maxn;
char maxc;
int ans;
int Quanzhong[N];
int sum;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    //input
    int n;cin>>n;

    while(n--){
    	int x;char y;
    	cin>>x;
		cin>>y;


		for(int i=1;i<=x;i++)s+=y;
		Quanzhong[y]+=x;
		sum+=x;




	}

	//first ask is huawei
	string hui=s;
	reverse(s.begin(),s.end());
	if(hui==s){
        cout<<0;
        return 0;
	}

	s=hui;
	int l=0,r=s.size();
	while(l<=r){
        if(s[l]==s[r])l++,r--;
        else{
            if(Quanzhong[s[l]]<Quanzhong[s[r]])s[l]=s[r],Quanzhong[s[r]]++,ans++;
            else if(Quanzhong[s[l]]>Quanzhong[s[r]])s[r]=s[l],Quanzhong[s[l]]++,ans++;




        }
	}
    cout<<ans;
    return 0;
}

////这键盘手感是真稀烂吧

