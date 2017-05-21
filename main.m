%Unsorted
suffix='unsorted';
except={};
%Round One
draw('unsorted_round_1',suffix,[0 4000],except);
%Round two
except{end+1}=strcat('bubbleSort','_',suffix,'.csv');
except{end+1}=strcat('cockTailSort','_',suffix,'.csv');
except{end+1}=strcat('linkSort','_',suffix,'.csv');
except{end+1}=strcat('radixSort','_',suffix,'.csv');
draw('unsorted_round_2','unsorted',[0 2000],except);
%Round Three
except{end+1}=strcat('binInsertSort','_',suffix,'.csv');
except{end+1}=strcat('normalInsertSort','_',suffix,'.csv');
except{end+1}=strcat('normalSelectSort','_',suffix,'.csv');
draw('unsorted_round_3','unsorted',[0 200],except);
%Round Four
except{end+1}=strcat('binShellSelectSort','_',suffix,'.csv');
draw('unsorted_round_4','unsorted',[0 10],except);


%Sorted
suffix='sorted';
except={};
draw('sorted',suffix,[0 4000],except);
