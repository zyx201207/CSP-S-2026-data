#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
};
node s1[200010];
node s2[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s1[i].a>>s1[i].c;
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        s2[n-i+1]=s1[i];
    }
    int i=1,j=1;
    while(i<=n&&j<=n){        
        while(i<=n&&j<=n&&s1[i].a>s2[j].a){
            s1[i].a-=s2[j].a;
            if(s1[i].c!=s2[j].c)cnt+=s2[j].a;
            j++;
        }      
        if(s1[i].c!=s2[j].c){
            cnt+=s1[i].a;
            s2[j].a-=s1[i].a;
            i++;
        }else{
			s2[j].a-=s1[i].a;
			i++;
		}		
        if(s1[i].a==0)i++;
        if(s2[j].a==0)j++;     
    }
    cout<<cnt/2;
    return 0;
}
