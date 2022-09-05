
int partition(vector<int>& arr,int s,int e){
  int pivot = arr[s];
  int count =0;
  for(int i=s+1;i<=e;i++){
    if(arr[i]<=pivot){
      count++;
    }
  }
  int pivotIndex = s+count;
  swap(arr[pivotIndex],arr[s]);
  int i=s;
  int j=e;
    while(i<pivotIndex && j>pivotIndex){
    while(arr[i]<=pivot){
      i++;
    }
    while(arr[j] > pivot){
      j--;
    }
    if(i<pivotIndex && j>pivotIndex){
      swap(arr[i++],arr[j--]);
    }
    }
  return pivotIndex;
}
void solve(vector<int>& arr,int s,int e){
  if(s>=e){
    return;
  }
  int pivot=partition(arr,s,e);
  
    solve(arr,s,pivot-1);
    solve(arr,pivot+1,e);
  
}


vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    int n = arr.size();
    solve(arr,0,n-1);
    return arr;
}
