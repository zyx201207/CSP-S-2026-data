#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
	long long ans = 0;
    //char S[100000];
    scanf("%d",&n);
    long long nums[200000];
    long  kinds = 0;
    char words[200000];
    for(int i = 0 ; i < n ; i++){
        int num;
        char word;
        scanf("%d %c",&num,&word);
        // for(int o = len ; o < len+num ; o++)
        // 	S[o]= word;
        if(word == words[kinds]){
            nums[kinds]+=num;
        }
        else{
            kinds+=1;
            words[kinds]=word;
            nums[kinds]=num;
        }
    }
    int l=0,r=kinds-1,nnow = 0;
    while(l<r){
        
        nnow +=nums[l];
        nnow -=nums[r];
        if(words[l] = words[r])
            ans+=max(nnow,-nnow);
        else{
            ans+=min(nums[l],nums[r]);
        }
        l++;r--;

    }
    printf("%lld",ans);
    return 0;
}

