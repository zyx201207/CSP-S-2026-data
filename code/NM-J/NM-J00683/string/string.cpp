#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a;
ll cnt=0;
char c;
vector<pair<int,char> >s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        s.push_back({a,c});
    }
    int l=0,r=n-1;
    while(l<=r){
        int lai=s[l].first,rai=s[r].first;
        char lci=s[l].second,rci=s[r].second;
        if(lci==rci){
            if(lai==rai){
			 	l++;
				r--;
			}else if(lai>rai){
                s[l].first=lai-rai;
                r--;
            }else{
                s[r].first=rai-lai;
                l++;
            }
        }else{
            if(lai==rai){
				l++;
				r--;
				cnt+=(ll)lai;
			}else if(lai>rai){
                s[l].first=lai-rai;
                r--;
                cnt+=(ll)rai;
            }else{
                s[r].first=rai-lai;
                l++;
                cnt+=(ll)lai;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
