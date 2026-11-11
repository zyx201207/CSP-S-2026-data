#include<bits/stdc++.h>
using namespace std;
long long n,s[200020],h=0,sy=0;
char c[200020];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>c[i];
    }
    long long i=1,j=n;
    bool f;
    while(i<j){
        if(sy==0){
            if(c[i]==c[j]){
                if(s[i]==s[j]){
                    i++;
                    j--;
                }
                else if(s[i]>s[j]){
                    sy=s[i]-s[j];
                    f=0;
                    j--;
                }
                else if(s[j]>s[i]){
                    sy=s[j]-s[i];
                    f=1;
                    i++;
                }
            }
            else{
                if(s[i]>s[j]){
                    h=h+s[j];
                    sy=s[i]-s[j];
                    f=0;
                    j--;
                }
                else if(s[j]>s[i]){
                    h=h+s[i];
                    sy=s[j]-s[i];
                    f=1;
                    i++;
                }
                else if(s[i]==s[j]){
                    h=h+s[i];
                    i++;
                    j--;
                }
            }
        }
        else{
            if(f==0){
                if(c[i]==c[j]){
                    if(sy==s[j]){
                        i++;
                        j--;
                    }
                    else if(sy>s[j]){
                        sy=sy-s[j];
                        f=0;
                        j--;
                    }
                    else if(s[j]>sy){
                        sy=s[j]-sy;
                        f=1;
                        i++;
                    }
                }
                else{
                    if(sy>s[j]){
                        h=h+s[j];
                        sy=sy-s[j];
                        f=0;
                        j--;
                    }
                    else if(s[j]>sy){
                        h=h+sy;
                        sy=s[j]-sy;
                        f=1;
                        i++;
                    }
                    else if(sy==s[j]){
                        h=h+sy;
                        i++;
                        j--;
                    }
                }
            }
            if(f==1){
                if(c[i]==c[j]){
                    if(s[i]==sy){
                        i++;
                        j--;
                    }
                    else if(s[i]>sy){
                        sy=s[i]-sy;
                        f=0;
                        j--;
                    }
                    else if(sy>s[i]){
                        sy=sy-s[i];
                        f=1;
                        i++;
                    }
                }
                else{
                    if(s[i]>sy){
                        h=h+sy;
                        sy=s[i]-sy;
                        f=0;
                        j--;
                    }
                    else if(sy>s[i]){
                        h=h+s[i];
                        sy=sy-s[i];
                        f=1;
                        i++;
                    }
                    else if(s[i]==sy){
                        h=h+s[i];
                        i++;
                        j--;
                    }
                }
            }
        }
    }
    cout<<h;
    return 0;
}
