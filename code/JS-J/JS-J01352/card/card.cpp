#include<bits/stdc++.h>
using namespace std;
int n,m,a[325799],res[325799];
bool memo[325799];
stack<int> st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=1;k<=n;k++)
    {
        //memset(memo,0,sizeof(memo));
        for(int i=k;i<=n;i++)
        {
            if(memo[a[i]]==1)
            {
                while(st.top()!=a[i])
                {
                    memo[st.top()]=0;
                    st.pop();
                }
            }
            else
            {
                memo[a[i]]=1;
                st.push(a[i]);
            }
        }
        while(!st.empty())
        {
            memo[st.top()]=0,res[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<' ';
    return 0;
}
//Switch on the power line
//Remember to put on the protection
//Lay down your pieces
//and let's begin the object creation
//Fill in my data
//parameters intallization
//Set up our new world
//and let's begin the simulation
//If i'm a set of points
//then i will give you my dimension
//If i'm a circle
//then i will give you my circumrefrence
//If i'm a sine wave
//then you can sit on all my tangent
//If i approach infinity
//then you can be my limitation
//Oh switch my current to AC to DC
//and then blind my vision
//So dizzy so dizzy
//Oh we can travel to AD to BC
//and we can unite so deeply so deeply
//If i can
//If i can
//do all the simulations
//then i can
//then i can
//be your only satisfaction
//If i can make you happy
//i'll run the excution
//Though we are trapped we are trapped
//in the strange strange simutation
//[Excution]
//If i'm an eggplant
//then i will give you my [Excution]
//If i'm a tomato
//then i will give you my [Excution]
//If i'm a tabby cat
//then i purr your enjoyment
//If i'm the only God
//then you are proof of my existence
//Oh switch my gender
//to F to M
//and do whatever
//from a.m. to p.m.
//Switch my role
//to S to M
//and we can enter
//the trance the trance
//If i can
//if i can feel your vibration
//then i can
//then i can finally be completion
//thought you are left
//you are left
//you are left
//you are left
//you are left
//you are left
//you are left
//in isolation
//If i can
//if i can erase all the pointless fragments
//then maybe
//then maybe
//you won't leave me so disheart
//Challenging your God
//you have made some illegal arguments
