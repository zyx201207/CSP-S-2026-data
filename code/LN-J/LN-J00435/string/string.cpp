#include <bits/stdc++.h>

using namespace std;
 long long a[10000005],n,cnt=0;

    char s[10000005];
int main()
{
     freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i]>>s[i];
  }

  long long i=1,j=n;

  while(i<=j){
    if(s[i]==s[j]){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else {
            if(a[i]>a[j]){

                a[i]-=a[j];
                j--;
            }
            if(a[i]<a[j]){

                a[j]-=a[i];
            i++;
}
        }
    }
    else{
            if(a[i]==a[j]){
               cnt+=a[i];
                i++;
            j--;
               }
            if(a[i]>a[j]){
                    cnt+=a[j];
                a[i]-=a[j];
                j--;
            }
            if(a[i]<a[j]){
            cnt+=a[i];
                a[j]-=a[i];
            i++;
}
        }


    }

  cout<<cnt<<endl;
    return 0;
}
