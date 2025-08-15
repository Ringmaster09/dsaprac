def union_sorted_arrays(arr1, arr2):
    i, j = 0, 0
    union = []

    while i < len(arr1) and j < len(arr2):
        # Skip duplicates in arr1
        if i > 0 and arr1[i] == arr1[i - 1]:
            i += 1
            continue
        # Skip duplicates in arr2
        if j > 0 and arr2[j] == arr2[j - 1]:
            j += 1
            continue

        if arr1[i] < arr2[j]:
            union.append(arr1[i])
            i += 1
        elif arr2[j] < arr1[i]:
            union.append(arr2[j])
            j += 1
        else:  # equal
            union.append(arr1[i])
            i += 1
            j += 1

    # Append remaining elements from arr1
    while i < len(arr1):
        if i == 0 or arr1[i] != arr1[i - 1]:
            union.append(arr1[i])
        i += 1

    # Append remaining elements from arr2
    while j < len(arr2):
        if j == 0 or arr2[j] != arr2[j - 1]:
            union.append(arr2[j])
        j += 1

    return union


# Example
arr1 = [1, 2, 2, 3, 4]
arr2 = [2, 3, 5, 6]
print(union_sorted_arrays(arr1, arr2))
# Output: [1, 2, 3, 4, 5, 6]
