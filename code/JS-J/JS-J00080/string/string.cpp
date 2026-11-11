#include<bits/stdc++.h>
using namespace std;
struct strings{
    long long number;
    char word;
};
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   cin>>n;
   strings CCF[n+1];
   long long ans=0;
   for(int i=0;i<n;++i){
        cin>>CCF[i].number>>CCF[i].word;
   }
   int begin=0;
   int end=n-1;
   while(begin<end){
        if(CCF[begin].word==CCF[end].word){
            if(CCF[begin].number==CCF[end].number){
                begin++;
                end--;
            }
            else if(CCF[begin].number>CCF[end].number){
                CCF[begin].number-=CCF[end].number;
                end--;
            }
            else if(CCF[begin].number<CCF[end].number){
                CCF[end].number-=CCF[begin].number;
                begin++;
            }
        }
        else{
            if(CCF[begin].number==CCF[end].number){
                begin++;
                end--;
                ans+=CCF[begin].number;
            }
            else if(CCF[begin].number>CCF[end].number){
                CCF[begin].number-=CCF[end].number;
                ans+=CCF[end].number;
                end--;
            }
            else if(CCF[begin].number<CCF[end].number){
                CCF[end].number-=CCF[begin].number;
                ans+=CCF[begin].number;
                begin++;
            }
        }
   }
   cout<<ans;
}
