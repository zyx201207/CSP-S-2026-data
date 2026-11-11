#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long len;
long long tarr[200005];
char tcrr[200005];
long long arr[200005];
char crr[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&tarr[i]);
        scanf(" %c",&tcrr[i]);
        len+=tarr[i];
    }
    int idx=1;
    long long temp=0;
    for(int i=1;i<=n;i++){
        long long ta=tarr[i];
        char tc=tcrr[i];
        if(temp*2<=len&&(temp+tarr[i])*2>=len){
            if(len%2==0){
                int t=len/2-temp;
                int t2=ta-t;
                arr[idx]=t;
                crr[idx]=tc;
                idx++;
                arr[idx]=t2;
                crr[idx]=tc;
                idx++;
            }else{
                int t=len/2-temp;
                int t2=ta-t-1;
                if(t>0){
                    arr[idx]=t;
                    crr[idx]=tc;
                    idx++;
                }
                arr[idx]=1;
                crr[idx]=tc;
                idx++;
                if(t2>0){
                    arr[idx]=t2;
                    crr[idx]=tc;
                    idx++;
                }
            }
        }else if(temp*2==len){
            arr[idx]=ta;
            crr[idx]=tc;
            idx++;
        }else{
            arr[idx]=ta;
            crr[idx]=tc;
            idx++;
        }
        temp+=tarr[i];
    }
 //   for(int i=1;i<idx;i++){
 //       cout<<arr[i]<<" "<<crr[i]<<endl;
 //   }
    long long ans=0;
    int i=1,j=idx-1;
    while(i<j){
        if(arr[i]>arr[j]){
            if(crr[i]!=crr[j]){
                ans+=arr[j];
            }
            arr[i]-=arr[j];
            j--;
        }
        if(arr[i]==arr[j]){
            if(crr[i]!=crr[j]){
                ans+=arr[j];
            }
            i++;
            j--;
        }
        if(arr[i]<arr[j]){
            if(crr[i]!=crr[j]){
                ans+=arr[i];
            }
            arr[j]-=arr[i];
            i++;
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
